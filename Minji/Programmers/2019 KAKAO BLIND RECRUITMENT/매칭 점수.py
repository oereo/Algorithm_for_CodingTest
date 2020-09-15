import re

def solution(word, pages):
    answer = 0
    basic_score = {}
    all_link_list = []
    link_count = {}
    original_page = []
    for page in pages:
    # 현재 페이지 URL 저장
        url = re.findall('<meta property="og:url" content="https://(.*)"/>', page)[0]
        original_page.append(url)
        # 외부 링크 저장: (From, To)
        links = page.split('a href="https://')[1:]
        for link in links:
            all_link_list.append((url, link.split('"')[0]))
        # 기본 점수 및 외부 링크 개수 저장
        link_count[url] = len(links)
        basic_score[url] = re.sub('[^a-z]+', '.', page.lower()).split('.').count(word.lower())
        print(basic_score)
    # 링크 점수 계산
    link_score = {}
    for url, link in all_link_list:
        if link in link_score:
            link_score[link] += basic_score[url] / link_count[url]
        else:
            link_score[link] = basic_score[url] / link_count[url]
        
    # 최종 점수 계산
    score = {}
    for url in basic_score:
        score[url] = basic_score[url]
    for url in link_score:
        if url in score:
            score[url] += link_score[url]
    # 최종 점수가 제일 높은 페이지 인덱스 반환
    max_value = -1
    index = -1
    count = 0
    for url in original_page:
        if score[url] > max_value:
            max_value = score[url]
            index = count
        count += 1
    return index