db.createCollection('GAMES', //create Collection
{
   "validator":{
      "$jsonSchema":{
         "bsonType":"object",
         "properties":{
            "game":{
               "type":"object",
               "properties":{
                  "datetime":{
                     "bsonType":"date"
                  },
                  "venue":{
                     "type":"string"
                  },
                  "htname":{
                     "type":"string"
                  },
                  "htscore":{
                     "type":"number"
                  },
                  "atname":{
                     "type":"string"
                  },
                  "atscore":{
                     "type":"number"
                  },
                  "fname":{
                     "type":"string"
                  },
                  "lname":{
                     "type":"string"
                  },
                  "ref ref":{
                     "type":"string"
                   },
                  "has":{
                     "bsonType":"array",
                     "items":{"bsonType":"object",
                     "properties":{
                        "team":{
                           "type":"object",
                           "properties":{
                              "name":{
                                 "type":"string"
                              },
                              "cdate":{
                                 "bsonType":"date"
                              },
                              "mcoach":{
                                 "type":"string"
                              },
                              "locatedat":{
                                 "type":"string",
                                 "properties":{
                                    "city":{
                                       "bsonType":"object",
                                       "properties":{
                                          "name":{
                                             "type":"string"
                                          },
                                          "population":{
                                             "type":"number"
                                          },
                                          "country":{
                                             "type":"string"
                                          },
                                          "tname":{
                                             "type":"string"
                                          }
                                       },

                                       "required":["name", "population", "country", "tname"],
                                       "additionalProperties":false
                                    }
                                 },

                                 "required":["city"],
                                 "additionalProperties":false

                           }
                     },
                     "required":["name", "cdate", "mcoach"],
                     "additionalProperties":false
                   }
                  },
                  "required":["team"],
                  "additionalProperties":false
                }
               }
            },
            "required":["datetime", "venue", "htname", "htscore", "atname", "atscore", "fname", "lname"],
            "additionalProperties":false
          },
            "referee":{
               "bsonType":"object",
               "properties":{
                  "fname":{
                     "type":"string"
                  },
                  "lname":{
                     "type":"string"
                  },
                  "cname":{
                     "type":"string"
                  },
                  "livesin":{
                     "bsonType":"object",
                     "properties":{
                        "city":{
                           "bsonType":"object",
                           "properties":{
                              "name":{
                                 "type":"string"
                              },
                              "population":{
                                 "type":"number"
                              },
                              "country":{
                                 "type":"string"
                              },
                              "tname":{
                                 "type":"string"
                              }
                           },

                           "required":["name", "population", "country", "tname"],
                           "additionalProperties":false
                        }
                     },

                     "required":["city"],
                     "additionalProperties":false

                }
              },
              "required":["fname", "lname", "cname"],
              "additionalProperties":false
            }
         }
      }
   }});


db.GAMES.insert({ //validates correctly

   "game":{
      "datetime":new Date('2020-09-03'),
      "venue":"Summoners Rift",
      "htname":"SKT T1",
      "htscore":10,
      "atname":"Cloud 9",
      "atscore":8,
      "fname":"Nunu",
      "lname":"Willump",
      "has":[{"team":{
         "name":"SKT T1",
         "cdate":new Date('2020-07-11'),
         "mcoach":"Tyler 1",
         "locatedat":{"city":{
             "name":"Noxus",
             "population":4000000,
             "country":"Australia",
             "tname":"SKT T1"
          }}
      }},
      {"team":{
         "name":"Cloud 9",
         "cdate":new Date('01-08-2020'),
         "mcoach":"Pants are Dragon",
         "locatedat":{"city":{
             "name":"Piltover",
             "population":9000000,
             "country":"United States",
             "tname":"Cloud 9"
          }}
      }}]
   },
   "referee":{
      "fname":"Nunu",
      "lname":"Willump",
      "cname":"Noxus",
      "livesin":{"city":{
          "name":"Noxus",
          "population":9000,
          "country":"Australia",
          "tname":"SKT T1"
       }}
   },
});

db.GAMES.insert({ //validates correctly

   "game":{
      "datetime":new Date('2020-10-12'),
      "venue":"Twisted Tree Line",
      "htname":"TSM",
      "htscore":5,
      "atname":"SKT T1",
      "atscore":12,
      "fname":"Xin",
      "lname":"Zhao",
      "has":[{"team":{
         "name":"SKT T1",
         "cdate":new Date('2020-07-11'),
         "mcoach":"Tyler 1",
         "locatedat":{"city":{
             "name":"Noxus",
             "population":4000000,
             "country":"Australia",
             "tname":"SKT T1"
          }}
      }},
      {"team":{
         "name":"TSM",
         "cdate":new Date('2020-09-21'),
         "mcoach":"Yassuo",
         "locatedat":{"city":{
             "name":"Demacia",
             "population":2000000,
             "country":"Lebanon",
             "tname":"TSM"
          }}
      }}]
   },
   "referee":{
      "fname":"Xin",
      "lname":"Zhao",
      "cname":"Demacia",
      "livesin":{"city":{
          "name":"Demacia",
          "population":2000000,
          "country":"Lebanon",
          "tname":"TSM"
       }}
   },
});

db.GAMES.insert({ //Validates Correctly

   "game":{
      "datetime":new Date('2020-11-16'),
      "venue":"Summoners Rift",
      "htname":"SKT T1",
      "htscore":15,
      "atname":"Cloud 9",
      "atscore":3,
      "fname":"Nunu",
      "lname":"Willump",
      "has":[{"team":{
         "name":"SKT T1",
         "cdate":new Date('2020-07-11'),
         "mcoach":"Tyler 1",
         "locatedat":{"city":{
             "name":"Noxus",
             "population":4000000,
             "country":"Australia",
             "tname":"SKT T1"
          }}
      }},
      {"team":{
         "name":"Cloud 9",
         "cdate":new Date('2020-08-01'),
         "mcoach":"Pants are Dragon",
         "locatedat":{"city":{
             "name":"Piltover",
             "population":9000000,
             "country":"United States",
             "tname":"Cloud 9"
          }}
      }}]
   },
   "referee":{
      "fname":"Nunu",
      "lname":"Willump",
      "cname":"Noxus",
      "livesin":{"city":{
          "name":"Noxus",
          "population":9000,
          "country":"Australia",
          "tname":"SKT T1"
       }}
   },
});

db.GAMES.insert({ //Does not validate because the referee's cities tean name is the wrong data type


     "game":{
        "datetime":new Date('2020-11-16'),
        "venue":"Summoners Rift",
        "htname":"SKT T1",
        "htscore":15,
        "atname":"Cloud 9",
        "atscore":3,
        "fname":"Nunu",
        "lname":"Willump",
        "has":[{"team":{
           "name":"SKT T1",
           "cdate":new Date('2020-07-11'),
           "mcoach":"Tyler 1",
           "locatedat":{"city":{
               "name":"Noxus",
               "population":4000000,
               "country":"Australia",
               "tname":"SKT T1"
            }}
        }},
        {"team":{
           "name":"Cloud 9",
           "cdate":new Date('2020-08-01'),
           "mcoach":"Pants are Dragon",
           "locatedat":{"city":{
               "name":"Piltover",
               "population":9000000,
               "country":"United States",
               "tname":"Cloud 9"
            }}
        }}]
     },
     "referee":{
        "fname":"Nunu",
        "lname":"Willump",
        "cname":"Noxus",
        "livesin":{"city":{
            "name":"Noxus",
            "population":9000,
            "country":"Australia",
            "tname":0000
         }}
     },
  });
