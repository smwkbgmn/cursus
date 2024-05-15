#!/usr/bin/python3
# -*- coding: utf-8 -*-

import os
import sys

if __name__ == "__main__":
    len = os.getenv("CONTENT_LENGTH");
    query_str = sys.stdin.read()


    html_text = '<!DOCTYPE html>\n<html>\n<head>\n'
    html_text += '\t<title>'+'test'+'</title>\n'
    html_text += '\t<meta charset="utf-8">\n'
    html_text += '</head>\n\n'
    html_text += '<body>\n'

    html_text += '<h3>Hello world by python cgi</h3>'

    if query_str!= None:
        html_text += 'String from browser: ' + query_str   


    html_text += '</body>\n</html>\n'

    print (html_text)
출처: https://kibua20.tistory.com/107 [모바일 SW 개발자가 운영하는 블로그:티스토리]