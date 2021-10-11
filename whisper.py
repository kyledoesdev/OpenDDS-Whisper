import argparse
import sys
import requests, os, key

API_KEY = os.getenv('YELP_API_KEY')
ENDPOINT = 'https://api.yelp.com/v3/businesses/search'
HEADERS = {'Authorization': 'bearer %s' % API_KEY}

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-type', type=str, default='coffee',
                        help='What is the type of business?')
    parser.add_argument('-rad', type=int, default=10000,
                        help='What is distance to a business?')
    parser.add_argument('-lat', type=float, default=32.0,
                        help='What is the latitude?')
    parser.add_argument('-long', type=float, default=117.0,
                        help='What is the longitude?')
    parser.add_argument('-num', type=int, default=10,
                        help='How many businesses to display')
    args = parser.parse_args()
    sys.stdout.write(str(yelpbiz(args)))

    
def yelpbiz(args):
    PARAMETERS = {'term':args.type,
                  'radius':args.rad,
                  'latitude':args.lat,
                  'longitude':args.long}
    
    n = args.num
    
    #make the request itself
    response = requests.get(url = ENDPOINT, params = PARAMETERS, headers = HEADERS)

    #convert JSON string to a dictionary
    business_data = response.json()

    biz=[]
    for b in business_data['businesses']:
        biz.append(b['name'])

    for i in range(n):
        print(biz[i])


if __name__ == '__main__':
    main()
