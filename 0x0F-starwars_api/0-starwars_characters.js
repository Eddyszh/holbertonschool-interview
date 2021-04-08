#!/usr/bin/node
const { argv } = require('process');
const request = require('request');

request('https://swapi-api.hbtn.io/api/films/' + argv[2], function (err, res, body) {
  if (err) {
    return;
  }
  const json = JSON.parse(body);
  const list = [];
  for (const character of json.characters) {
    list.push(new Promise((resolve, reject) => {
      request(character, function (err, res, body) {
        if (err) {
          reject(err);
        }
        const names = JSON.parse(body).name;
        resolve(names);
      });
    }));
  }
  Promise.all(list).then((names) => {
    names.forEach((name) => {
      console.log(name);
    });
  });
});
