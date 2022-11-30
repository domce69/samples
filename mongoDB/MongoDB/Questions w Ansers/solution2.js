/* (1) Save information about a customer key, name, and nation of all customers from SUDAN or ROMANIA or CANADA into a collection SUROCAN. Display in a pretty format without document identifiers the contents of a collection SUROCAN. */;
db.tpchr.aggregate([{ $match : { "CUSTOMER.nation" :{$in:[ "SUDAN", "ROMANIA", "CANADA"]}}},{$project: {"CUSTOMER.customer key" : 1, "CUSTOMER.name" : 1, "CUSTOMER.nation" : 1}}, {$out: "SUROCAN"}]);
db.SUROCAN.find({"CUSTOMER": {$exists : true}},{"_id" : 0 }).pretty();

/* (2) Save all information about the supply costs (supplycost)of a part with a name floral moccasin royal powder burnished into a collection supplycosts that consists of the documents like {"supply cost": a-value-of-supply-cost}.Display in a pretty format without document identifiers all documents in a collection "supplycosts. */;
db.tpchr.aggregate([{ $match : { "PART.name" :{$in:[ "floral moccasin royal powder burnished"]}}},{$unwind: "$PART.shipped"},{$group: {"_id": {"supply cost":"$PART.shipped.PARTSUPP.supplycost"}}},{$project: {"supply cost":"$_id.supply cost"}},{$out: "supplycosts"}]);
db.supplycosts.aggregate([{$project:{_id:0}}]).pretty()


/* (3) Find the total number of part shipments of the parts of type LARGE BURNISHED STEEL or SMALL BURNISHED STEEL. Display a result in a format {"total number  of shipments":integer-value}. */;
db.tpchr.aggregate([{$match : {$or : [{ "PART.type" : "LARGE BURNISHED STEEL" },{ "PART.type" : "SMALL BURNISHED STEEL" }]}},{$unwind : "$PART.shipped"},{$count : "total"},{$project : {"total number of shipments" : "$total"}},{$out : "totalShipments"}])
db.totalShipments.aggregate([{"$project":{"_id":0}}]).pretty()


/* (4) Find the total number of shipments per each part. List the results in a format {"total number of shipments":integer-value,"part key":integer-value"} */;

db.tpchr.aggregate([{$match : { "PART.shipped.PARTSUPP.partsupp_id" : { $exists : true }}}, {$group : {"_id" : {"shipmentamounts" : {$size : "$PART.shipped" }, "part key" : "$PART.part key" }}},{$project : { "total number of shipments" : "$_id.shipmentamounts" , "part key" : "$_id.part key"}},{$out : "totalshipments"}])
db.totalshipments.aggregate([{"$project":{"_id":0}}]).pretty();

/* (5) Find 5 largest extended prices (extended price) from all orders. List the results in a format {"customer key": integer-value,"order key":integer-value,"line number":integer-value,"price":floating-point-value}  */;
db.tpchr.aggregate([{$match:{"CUSTOMER.submits.ORDER.contains.LINEITEM.extended price" : {$exists:true}}},{$unwind:"$CUSTOMER.submits"},{$unwind:"$CUSTOMER.submits.ORDER.contains"} ,{$project:{_id:0, "customer key" : "$CUSTOMER.customer key", "order key" : "$CUSTOMER.submits.ORDER.order key", "line number" : "$CUSTOMER.submits.ORDER.contains.LINEITEM.line number" ,"price":{$max:"$CUSTOMER.submits.ORDER.contains.LINEITEM.extended price"}}},{$sort:{price:-1}},{$limit: 5}]);
