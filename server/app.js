//packages
import dotenv from "dotenv";
import express, { query, response } from "express";
import yelp from "yelp-fusion";
import request from "request";
import querystring from "querystring";

//configuration
'use strict';
dotenv.config();

const yelp_api_key = process.env.YELP_API_KEY;
const client = yelp.client(yelp_api_key);
var client_defined_quantity = 5; //hardcoded for now
var app = express();
var port = 3000;

app.get("/return_coffee_shops", function(req, res) {
  //Business search
  client.search({
    term: 'Coffee', //hardcoded for now
    location: 'san fransisco, ca', //hardcoded for now
  }).then(response => {
    for(var i = 0; i < client_defined_quantity; i++) {
      console.log(response.jsonBody.businesses[i].name);
    }
  }).catch(e => {
    console.log(e); //log error to console
  });

});


app.listen(port, () => console.log("Listening on port: " + port));