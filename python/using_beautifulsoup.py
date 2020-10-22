from urllib.request import urlopen
import ssl
from bs4 import BeautifulSoup

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input('Enter URL: ')
html = urlopen(url, context=ctx).read()
soup = BeautifulSoup(html, 'html.parser')

tags = soup('a')
for tag in tags :
    print('TAG:', tag)
    print()
    print('URL:', tag.get('href', None))
    print()
    print('Contents:', tag.contents[0])
    print()
    print('Attrs:', tag.attrs)
    print()
