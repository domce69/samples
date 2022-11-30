/* (1) Remove information about an address from the description of a customer who submitted an order with an order key 1031. Next list a complete description of a customer who submitted an order with an order key 1031. */;
db.tpchr.update({"CUSTOMER.submits.ORDER.order key" : 1031}, {$unset: {"CUSTOMER.address": "" }});
db.tpchr.find({"CUSTOMER.submits.ORDER.order key" : {$eq : 1031}}).pretty();

/* (2) Rename a key "shipped" to "shipped by" in the parts that have a retail price less than 902. Next, display all information about parts that have a retail price less than 902 */;
db.tpchr.update({"PART.retailprice" : {$lt : 902}}, {$rename: {"PART.shipped" : "shipped by"}});
db.tpchr.find({"PART.retailprice" : {$lt : 902}}).pretty();

/* (3) Increase an account balance of all suppliers from Japan by 50% of the present value. Next, display a supplier name, nation and balance of all suppliers from Japan in a pretty format. */;
db.tpchr.update({"SUPPLIER.nation" : "JAPAN"}, {$mul: {"SUPPLIER.acctbal": 1.5 }});
db.tpchr.find({"SUPPLIER.nation" : {$eq : "JAPAN"}}).pretty();

/* (4) Append to all parts that belong to a brand Brand#54 the following information about a new shipment: "partsupp_id" : "5_1","availqty" : 100,"supplycost" : 17,"ref supplier" : "1". Next list all information about all parts that belong to a brand Brand#60 in a pretty format */;
db.tpchr.update({"PART.brand" : "Brand#54  "}, {$push :{"PART.shipped" : {"PARTSUPP" : {"partsupp_id" :"5_1", "availqty" : 100, "supplycost" : 17, "ref supplier":1}}}});

db.tpchr.find({"PART.brand" : {$eq : "Brand#54  "}}).pretty();
/* (5) Remove information about an order that has a key 1031 submitted by a customer whose key is 8. Next, list all information about all orders submitted by a customer whose key is 8 */;
db.tpchr.update({"CUSTOMER.customer key" : 8}, {$pull : {"CUSTOMER.submits" : {"ORDER.order key" :{$eq :  1031}}}});
db.tpchr.find({"CUSTOMER.customer key" : 8}).pretty();
