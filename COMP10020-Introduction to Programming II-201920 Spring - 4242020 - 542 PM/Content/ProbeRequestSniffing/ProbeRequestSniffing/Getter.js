var fs = require('fs');

var dburl = 'mongodb://dbadmin_001:MYaeelvCAw@ds055935.mongolab.com:55935/heroku_c52mc85f';
var monk = require('monk')
var db = monk(dburl);
var collection = db.get('subscriptions');



collection.find({}, function (err, res) {

	if(err) {
		console.log("Something went wrong with the DB!");
	} else {

		var twitterHandels = [];

		res.forEach( function(obj) {
			twitterHandels.push(obj.twitter);
		});

		fs.writeFile( 'output.txt', twitterHandels.join('\n'), function(err) {
			if(err){
				console.log("Error writing file!");
			} else {
				console.log("file written to HD! (output.txt)");
			}
		});
	}
});