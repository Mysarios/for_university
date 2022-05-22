var JSON_MSG_DT ={
    "ID_sender":0,
    "ID_getter":0,
    "Text_MSG": "HI, u are welcome"
}
function Get_json_MSG  (ID_S,ID_Get,TEXT){

    JSON_MSG_DT.ID_sender = ID_S;
    JSON_MSG_DT.ID_getter =ID_Get;
    JSON_MSG_DT.Text_MSG=TEXT;



    var params = new URLSearchParams();
    params.set('Quest', 'Write_MSG');
    params.set('Json', JSON.stringify(JSON_MSG_DT));

    fetch("http://localhost:63342", {
        method: "POST",
        body: params
    }).then(function(response) {
        // Стоит проверить код ответа.
        response.text().then(responseText => alert(responseText));
        if (!response.ok) {
            // Сервер вернул код ответа за границами диапазона [200, 299]
            return Promise.reject(new Error(
                'Response failed: ' + response.status + ' (' + response.statusText + ')'
            ));
        }
        // Далее будем использовать только JSON из тела ответа.
        return response.json();
    })
}


//Кнопка ВЕРНУТЬСЯ НА ВХОД
const Register_form_btn = document.getElementById("close_form_message_btn")
Register_form_btn.addEventListener("click",()=>{
    document.location.href = "INDEX.html"
})

//Кнопка НОВОЕ СООБЩЕНИЕ
const New_mail_btn = document.getElementById("new_mail_btn");
New_mail_btn.addEventListener("click",()=>{
    document.getElementById("block_new_message_id").style.display="block"
    document.getElementById("mail_id").style.opacity= "0.3";

})

//КНОПКА ОТПРАВИТЬ В ФОРМЕ НОВОЕ СООБЩЕНИЕ
const Send_new_message_btn = document.getElementById("Send_button");
Send_new_message_btn.addEventListener("click",()=>{

    const Name_new_message = document.getElementById("name_new")
    const New_text_message = document.getElementById("textarea_new")
    //Name_new_message.value = ""
    //New_text_message.value = ""

    //Контейнер для отправленных сообщений
    const container = document.getElementById("container_form_id");

    //Имя кому отправляем
    const Name_container = document.createElement("div");
    Name_container.className = "Name_input";
    Name_container.innerHTML = Name_new_message.value;

    //Отправленное сообщений
    const Textarea_container = document.createElement("div");
    Textarea_container.className = "TextArea_input";

    if(New_text_message.value.length <= 40){
        Textarea_container.innerHTML = New_text_message.value;
    }else{
        Textarea_container.innerHTML = New_text_message.value.slice(1,40) + "...";
    }


    //Обьединяем имя и сообщение в один блок
    const main_div = document.createElement("div");
    main_div.className = "main_class";
    main_div.appendChild(Name_container);
    main_div.appendChild(Textarea_container);

    //Добавляем к контейнеру
    container.appendChild(main_div)

    const line_div = document.createElement("hr");
    line_div.className = "hr";
    container.appendChild(line_div);

    document.getElementById("mail_id").style.opacity= "1";
    document.getElementById("block_new_message_id").style.display="none"

    Get_json_MSG(Name_new_message.value,Name_new_message.value,New_text_message.value);
    //alert(Name_new_message.value + "  " + New_text_message.value);
})




//Кнопка Входящие
const Incoming_message_btn = document.getElementById("incoming_message")
Incoming_message_btn.addEventListener("click",()=>{
    document.getElementById("container_form_id").style.display = "none";
    document.getElementById("outgoing_container_id").style.display = "block";
})

//Кнопка Отправленные
const Outgoing_message_btn = document.getElementById("outgoing_message")
Outgoing_message_btn.addEventListener("click",()=>{
    document.getElementById("outgoing_container_id").style.display = "none";
    document.getElementById("container_form_id").style.display = "block";

})

//Клик на сообщение
const click_message = document.getElementsByClassName("main_class")[2];

click_message.addEventListener("click",()=>{
    alert("Все работает")
    document.getElementsByClassName("main_class")[0].style.backgroundColor = "blue"
})
