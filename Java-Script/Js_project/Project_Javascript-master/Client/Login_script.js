const button_register1 = document.getElementById("register_form1");
const button_register2 = document.getElementById("register_form2");

const button_entrance1 = document.getElementById("entrance_form1");
const button_entrance2 = document.getElementById("entrance_form2");

var Js_Reg =
    {
            "ID": 1,
            "Name": [{
                    "First": "Admin",
                    "Second": "Admin",
                }],

            "Password": 132456789
        }

//Форма Регистрация Кнопка Регистрация
function Registration  (F_name,S_name,ID,Password){
    Js_Reg.ID=ID;
    Js_Reg.Name[0]=F_name;
    Js_Reg.Name[1]=S_name;
    Js_Reg.Password=Password;

    var params = new URLSearchParams();
    params.set('Quest', 'Register');
    params.set('Json', JSON.stringify(Js_Reg));

    fetch("http://localhost:63342", {
        method: "POST",
        body: params
    }).then(function(response) {
        // Стоит проверить код ответа.
        response.text().then(responseText => alert(responseText));
        /*if (!response.ok) {
            // Сервер вернул код ответа за границами диапазона [200, 299]
            return Promise.reject(new Error(
                'Response failed: ' + response.status + ' (' + response.statusText + ')'
            ));
        }
        // Далее будем использовать только JSON из тела ответа.
        //return response.json();*/
    })
}


button_register1.addEventListener("click",()=>{
    const name_register = document.getElementById("Register_name");
    const family_register = document.getElementById("Register_family");
    const ID_register = document.getElementById("Register_ID");
    const Password_register = document.getElementById("Register_password");
    const Password2_register = document.getElementById("Register_return_password");

    //Просто проверил считываются ли данные
    alert(Password_register.value)

    if(name_register.value === "" || family_register.value === "" || ID_register.value === "" || Password_register.value === "" || Password2_register.value === ""  ){
        alert("Введите данные полностью");
        return false;
    }else {
        if (Password_register.value !== Password2_register.value) {
            alert("Пароли не совпадают");
            Password_register.value = "";
            Password2_register.value = "";
            return false
        }else{
            if (Password_register.value.length < 8){
                alert("Пароль должен содержать более 8-ми символов")
                return false
            }else {
                Registration(name_register.value,family_register.value,ID_register.value,Password_register.value);
                document.location.href = "MY_MAIL.html.html";
            }
        }
    }

})

//Форма Регистрация Кнопка Вход
button_register2.addEventListener("click",()=>{
    document.getElementById("register_form_id").style.display="none";
    document.getElementById("entrance_form_id").style.display="block";
})

//Форма Вход Кнопка Регистрация
button_entrance1.addEventListener("click",()=>{
    document.getElementById("entrance_form_id").style.display="none";
    document.getElementById("register_form_id").style.display="block";
})

//Форма Вход Кнопка Вход
button_entrance2.addEventListener("click",()=>{
    document.location.href = "MY_MAIL.html";
})
