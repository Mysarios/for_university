
const http = require('http');
const url = require("url");
const fs= require('fs')
const path = require('path');
const Data_B = require("./Data_Base.json");
const Data_Bas = require("./Data_Base.json");
const Data_Base = 'Server/Data_Base.json'
const DT_Msg_r = require("./Data_Base.json");
const DT_Msg = 'Server/MSG_DT.json'
const dirfile ="F:\\My Files\\Programming\\apps\\Server";
const { parse } = require('querystring');



http.createServer((request,response)=>{
        console.log(request.method);
        if(request.method == 'POST') {
            let body = '';
            request.on('data', chunk => {
                body += chunk.toString();
            });
            request.on('end', () => {

                if(body!='') {
                    const params = parse(body);

                    if (params.Quest == 'Register') {

                        console.log('Reg')

                        var check = 0;
                        Data_Bas.forEach(element => {
                            if (element.ID == JSON.parse(params.Json).ID) {
                                check = 1
                            }
                        })
                        if (check) {
                            response.end('This ID already in!')
                        } else {
                            response.end('All is ok!')
                            Add_json_DT(JSON.parse(params.Json));
                        }

                        // Get_Info()
                    }
                    if (params.Quest == 'Write_MSG') {

                        console.log('Msg')

                        Add_json_MSG_DT(JSON.parse(params.Json))
                        response.end('')
                        // Get_Info()
                        //var JS_Get=params.Json;
                        //console.log(JSON.parse(JS_Get).ID);
                    }
                }
            })
        }
        if(request.method == 'GET'){
            //response.end('ok')
        }
}).listen(63342);


function Add_json_DT(New_Json){

    var Data_Ba = fs.readFileSync(Data_Base,'utf8');
    var Buf=JSON.parse(Data_Ba);

    Buf.push(New_Json);

    fs.writeFile('Server/Data_Base.json',JSON.stringify(Buf),(err)=>{
        if(err) console.log('Error');
    });
}
function Add_json_MSG_DT(New_Json){

    var DT = fs.readFileSync(DT_Msg,'utf8');
    var Buf=JSON.parse(DT);

    Buf.push(New_Json);

    fs.writeFile('Server/MSG_DT.json',JSON.stringify(Buf),(err)=>{
        if(err) console.log('Error');
    });
}

function Get_Info(Numer){
    var Data_Bas = require("./Data_Base.json");
    return  Data_Bas[Numer];
}
