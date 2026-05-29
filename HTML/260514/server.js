const express = require('express');
const app = express();

app.set('view engine', 'ejs');
app.use(express.urlencoded({ extended: true }));

const chatData = [];

app.get('/', function(req,res){

    
    //메인화면 보여주기
    res.render('index', {chatData});
});

app.post('/chat', function(req,res){
    //채팅 메시지 저장처리
    const now = new Date();
    
    console.log(req.body.message);
    chatData.push(req.body.message + " (" + now.getHours() +":"+ now.getMinutes() + ")");

    res.redirect('/');
});

app.listen(80);
