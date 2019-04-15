const mysql = require('mysql');
const connection = mysql.createConnection({
    host     : 'db-intern.ciupl0p5utwk.us-east-1.rds.amazonaws.com', //mysql database name
    port     :  '3306',
    user     : 'dummyUser', //mysql database username
    password : 'dummyUser01', //mysql database password
    database : 'db_intern' //mysql database name
});

connection.connect((err) => {
    if (err) {
        throw err;
    }
    console.log('Connected to database');
});