import dotenv from "dotenv";
import express from "express";
import request from "request";
import querystring from "querystring";

const yelp_client_id = process.env.YELP_CLIENT_ID;
const yelp_api_key = process.env.YELP_API_KEY;

var app = express();
var port = 3000;

app.get("/", (req, res) => {
  res.send("Hello World");
});

app.listen(port, () => console.log("Listening on port" + port));