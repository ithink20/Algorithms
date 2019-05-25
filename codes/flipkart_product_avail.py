# author: @vikasc


from urllib2 import urlopen
from bs4 import BeautifulSoup

link = raw_input("Enter link : ")
#here.
html = urlopen(link)
page = html.read()
html.close()
soup = BeautifulSoup(page, "html.parser")

containers =  soup.find("span", {"class" : "_35KyD6"})
print (containers.text)

price = soup.findAll("div", {"class" : "_1vC4OE"})
avail = soup.find("div", {"class" : "_1S11PY"})
check = soup.find("div", {"class" : "_3xgqrA"})
if (check != None):
    print check.text
if (avail != None):
    print avail.text
print price[0].text
