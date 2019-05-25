const express = require('express');
const router = express.Router();
const mysql = require('mysql');
const bcrypt = require('bcryptjs');
var moment = require('moment');

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

//login page
router.get('/login', (req, res) => res.render('login'));
//register page
router.get('/register', (req, res) => res.render('register'));

//test
router.get('/', function (req, res, next) {
    connection.query('SELECT * FROM userData', function (error, results, fields) {
        if (error) throw error;
        res.send(JSON.stringify({ "status": 200, "error": null, "response": results }));
    });
});

//Register Handle
router.post('/register', (req, res) => {
    // console.log(req.body);
    // res.send('hello');
    var { name, email, phone, password, password2, time} = req.body;
    let errors = [];
    //check fields
    if (!name || !email || !phone || !password || !password2) {
        console.log(phone);
        errors.push({ msg: 'please fill in all fields' });
    }
    //check password match
    if (password != password2) {
        errors.push({ msg: 'passwords don\'t match' });
    }
    //check pass length
    if (password.length < 6) {
        errors.push({ msg: 'password should be atleast 6 characters' });
    }
    if (errors.length > 0) {
        res.render('register', {
            errors,
            name,
            email,
            phone,
            password,
            password2
        })
    } else {
        // res.send('validation passed');
        connection.query('SELECT emailId FROM userData WHERE emailId = "'+ email +'" ', function (error, results, fields) {
            if (results.length > 0) {
                errors.push({ msg: 'Email is already registered' });
                res.render('register', {
                    errors,
                    name,
                    email,
                    phone,
                    password,
                    password2
                })
            } else {
                //Hash password
                bcrypt.genSalt(10, (err, salt) => bcrypt.hash(password, salt, (err, hash) => {
                    if (err) throw err;
                    password = hash;
                    //save user
                    var time = moment().format();
                    connection.query('INSERT INTO userData VALUES ("' + name + '","' + email + '","' + phone + '","' + password + '","' + time + '")', function (error, res) {
                        if (error) throw error;
                        console.log(name + " is inserted");
                    });
                }));
                req.flash('success_msg', 'you are registered & can login!');
                res.redirect('/users/login');
            }
        });
    }
});

router.post('/login', (req, res) => {
    var email = req.body.email;
    var password = req.body.password;
    connection.query('SELECT * FROM userData WHERE emailId = "'+ email +'" ', function (error, results, fields) {
        if (error) throw error;
        //match password
        // TODO: compare is not working. check it.
        bcrypt.compare(password, results[0].password, function (err, isMatch) {
            if (isMatch == true) {
                console.log('user ' + results[0].userName + ' is matched. Wohooo!');
            } else {
                console.log('user doesn\'t match..');
            }
        });
    });
});

module.exports = router;
