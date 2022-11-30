/* (1)  Find all parts that belongs to a given brand. */;
db.tpchr.find({"PART.brand" : {$eq : "Brand#13  "}}, {"PART.brand" : 1}).pretty();
db.tpchr.createIndex({"PART.brand":1});
db.tpchr.getIndexes();
db.tpchr.find({"PART.brand" : {$eq : "Brand#13  "}}, {"PART.brand" : 1}).explain();
db.tpchr.dropIndex("PART.brand_1");

/* (2)  Find all parts that has a retail price greater than a given value. */;
db.tpchr.find({"PART.retailprice" : {$gt : 906}}, {"PART.retailprice" : 1}).pretty();
db.tpchr.createIndex({"PART.retailprice":-1});
db.tpchr.getIndexes();
db.tpchr.find({"PART.retailprice" : {$gt : 906}}, {"PART.retailprice" : 1}).explain();
db.tpchr.dropIndex("PART.retailprice_-1");

/* (3)  Find the names of all suppliers. */;
db.tpchr.find({"SUPPLIER.name" : {$exists : true}}, {"SUPPLIER.name" : 1}).pretty();
db.tpchr.createIndex({"SUPPLIER.name":1});
db.tpchr.getIndexes();
db.tpchr.find({"SUPPLIER.name" : {$exists : true}}, {"SUPPLIER.name" : 1}).explain();
db.tpchr.dropIndex("SUPPLIER.name_1");

/* (4)  Find the brands and types of all parts. */;
db.tpchr.find({"PART" : {$exists : true}}, {"PART.brand" : 1, "PART.type" : 1, _id : 0});
db.tpchr.createIndex({"PART" : 1});
db.tpchr.getIndexes();
db.tpchr.find({"PART" : {$exists : true}}, {"PART.brand" : 1, "PART.type" : 1, _id : 0}).explain();
db.tpchr.dropIndex("PART_1");

/* (5)  Find the names of customers who submitted at least one order; */;
db.tpchr.find({"CUSTOMER.submits.ORDER" : {$exists : true}}, {"CUSTOMER.name" : 1, _id : 0});
db.tpchr.createIndex({"CUSTOMER.submits.ORDER" : 1});
db.tpchr.getIndexes();
db.tpchr.find({"CUSTOMER.submits.ORDER" : {$exists : true}}, {"CUSTOMER.name" : 1, _id : 0}).explain();
db.tpchr.dropIndex("CUSTOMER.submits.ORDER_1");
