import argparse
import sys
import requests, os, key
import json

API_KEY = os.getenv('YELP_API_KEY')
ENDPOINT = 'https://api.yelp.com/v3/businesses/search'
HEADERS = {'Authorization': 'bearer %s' % API_KEY}

sys.path.insert(0, ".")

 
def yelpbiz(type, rad, lat, long, num):
    PARAMETERS = {'term': type,
                  'radius': int(rad),
                  'latitude': float(lat),
                  'longitude': float(long)}
    
    
    #make the request itself
    response = requests.get(url = ENDPOINT, params = PARAMETERS, headers = HEADERS)


    #convert JSON string to a dictionary
    business_data = response.json()
    bizes = business_data['businesses']

    with open('data.json', 'w') as f:
        json.dump(business_data, f)
#    os.system("make")
#    os.system("source ../../../setenv.sh")
    os.system("./run_test.pl")
    os.system("rm data.json")
#    f = open("demo2.txt", "a")
#    for i in range(int(num)):
#        f.write(biz[i]+"\n")
#    f.close()





