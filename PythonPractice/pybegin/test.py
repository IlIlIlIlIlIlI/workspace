import requests as rq
from bs4 import BeautifulSoup

domain  = 'https://www.biqukan.com/'
req = rq.get(url = domain)
html = req.text
bf = BeautifulSoup(html)
divs = bf.find_all('div', class_ = 'nav')
a_bf = BeautifulSoup(str(divs[0]))
divs_a = a_bf.find_all('a')
#blocks_bf = BeautifulSoup(str(divs_a))
print(divs_a)

