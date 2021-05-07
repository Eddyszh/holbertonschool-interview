#!/usr/bin/python3
"""Module to search in reddit api
"""
import requests


def count_words(subreddit, word_list, hot_list=[], after=None):
    """parses the title of all hot articles"""
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    headers = {'User-agent': 'I_dont_know'}
    params = {'limit': 100}
    if isinstance(after, str):
        if after != "STOP":
            params['after'] = after
        else:
            return print_words(word_list, hot_list)
    response = requests.get(url, headers=headers, params=params)
    if response.status_code != 200:
        return None
    data = response.json().get('data', {})
    after = data.get('after', 'STOP')
    if not after:
        after = "STOP"
    hot_list += [post.get('data', {}).get('title')
                 for post in data.get('children', [])]
    return count_words(subreddit, word_list, hot_list, after)


def print_words(word_list, hot_list):
    """Prints results"""
    count = {}
    for w in word_list:
        count[w] = 0
    for title in hot_list:
        for w in word_list:
            for t in title.lower().split():
                if t == w.lower():
                    count[w] += 1
    count = {k: v for k, v in count.items() if v > 0}
    words = list(count.keys())
    for word in sorted(words, reverse=True, key=lambda k: count[k]):
        print("{}: {}".format(word, count[word]))
