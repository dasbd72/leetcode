import argparse
import os

import requests

GRAPHQL_URL = "https://leetcode.com/graphql"
HEADERS = {
    "Content-Type": "application/json",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3",
    "Referer": "https://leetcode.com/problemset/all/",
}


class Args:
    add: bool = False
    daily: bool = False
    problem_id: int = None
    editor: str = "code"


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "-a",
        "--add",
        action="store_true",
        help="Git add",
    )
    parser.add_argument(
        "-d", "--daily", action="store_true", help="Get the daily problem"
    )
    parser.add_argument(
        "-p",
        "--problem_id",
        type=int,
        help="Get the problem by problem ID",
    )
    parser.add_argument(
        "-e",
        "--editor",
        type=str,
        help="Open the problem in the specified editor",
    )
    args = parser.parse_args(namespace=Args)
    if not args.daily and not args.problem_id:
        parser.error("No problem specified")
    return args


def get_daily_problem():
    # Define the GraphQL query
    query = {
        "query": """
            query questionOfToday {
                activeDailyCodingChallengeQuestion {
                    date
                    userStatus
                    link
                    question {
                        titleSlug
                        title
                        translatedTitle
                        acRate
                        difficulty
                        freqBar
                        frontendQuestionId: questionFrontendId
                        isFavor
                        paidOnly: isPaidOnly
                        status
                        hasVideoSolution
                        hasSolution
                        topicTags {
                            name
                            id
                            slug
                        }
                    }
                }
            }
        """,
        "variables": {},
        "operationName": "questionOfToday",
    }

    # Send POST request to the GraphQL endpoint
    response = requests.post(GRAPHQL_URL, json=query, headers=HEADERS)

    # Check if request was successful
    if response.status_code == 200:
        data = response.json()

        # Extract problem information from the response
        problem_data = data["data"]["activeDailyCodingChallengeQuestion"]

        # Extract the relevant fields
        date = problem_data["date"]
        question = problem_data["question"]
        problem_id = question["frontendQuestionId"]
        title = question["title"]
        title_slug = question["titleSlug"]
        difficulty = question["difficulty"]
        link = f"https://leetcode.com{problem_data['link']}"

        # Construct response
        response = {
            "date": date,
            "problem_id": problem_id,
            "title": title,
            "title_slug": title_slug,
            "difficulty": difficulty,
            "link": link,
        }
        return response
    else:
        raise Exception(
            f"Failed to retrieve the daily problem. Status code: {response.status_code}"
        )


def get_problem_by_problem_id(problem_id):
    for skip in [
        max(0, problem_id - problem_id % 50 - 1),
        problem_id - problem_id % 50,
    ]:
        # Define the GraphQL query
        query = {
            "query": """
                query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {
                problemsetQuestionList: questionList(
                    categorySlug: $categorySlug
                    limit: $limit
                    skip: $skip
                    filters: $filters
                ) {
                    total: totalNum
                    questions: data {
                    frontendQuestionId: questionFrontendId
                    titleSlug
                    title
                    difficulty
                    }
                }
                }
            """,
            "variables": {
                "categorySlug": "all-code-essentials",  # You can change the category here if needed
                "skip": skip,  # Start from the first problem
                "limit": 50,  # Set how many problems to retrieve in one request
                "filters": {},
            },
            "operationName": "problemsetQuestionList",
        }

        # Send POST request to the GraphQL endpoint
        response = requests.post(GRAPHQL_URL, json=query, headers=HEADERS)

        # Check if the request was successful
        if response.status_code == 200:
            data = response.json()

            # Extract the problems list
            questions = data["data"]["problemsetQuestionList"]["questions"]

            # Iterate through the problems and find the matching problem ID
            for question in questions:
                if question["frontendQuestionId"] == str(
                    problem_id
                ):  # Match the problem ID
                    problem_id = question["frontendQuestionId"]
                    title = question["title"]
                    title_slug = question["titleSlug"]
                    difficulty = question["difficulty"]
                    response = {
                        "problem_id": problem_id,
                        "title": title,
                        "title_slug": title_slug,
                        "difficulty": difficulty,
                    }
                    return response
        else:
            raise Exception(
                f"Failed to retrieve the problem list. Status code: {response.status_code}"
            )
    raise Exception(f"Problem with ID {problem_id} not found.")


def create_file(problem_id: int, title_slug: str):
    directory = "problems/{:04d}-{}".format(problem_id, title_slug)
    if not os.path.exists(directory):
        os.makedirs(directory)
    filename = f"{directory}/main.cpp"
    if not os.path.exists(filename):
        with open(filename, "w") as file:
            file.write("#include <bits/stdc++.h>\nusing namespace std;\n")
    return filename


def main():
    # Parse the command-line arguments
    args = parse_args()
    if args.daily:
        problem = get_daily_problem()
    elif args.problem_id:
        problem = get_problem_by_problem_id(args.problem_id)

    # Extract the problem details
    problem_id = int(problem["problem_id"])
    title = problem["title"]
    title_slug = problem["title_slug"]

    if args.add:
        # Get filename and add to git
        filename = create_file(problem_id, title_slug)
        code = os.system(f"git reset")
        print(f"Git reset returned code: {code}")
        code = os.system(f"git add {filename}")
        print(f"Git add returned code: {code}")
        code = os.system(f"git commit -m {problem_id:04d}")
        print(f"Git commit returned code: {code}")
    else:
        # Create and open the problem in the specified editor
        filename = create_file(problem_id, title_slug)
        print(f'Opening problem "{problem_id}. {title}" in {args.editor}')
        os.system(f"{args.editor} {filename}")


if __name__ == "__main__":
    main()
