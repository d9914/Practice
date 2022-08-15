document.addEventListener('DOMContentLoaded', function()
{
    let correct_button= document.querySelector("#correct");
    let false_button= document.querySelectorAll(".false");
    let message = document.querySelector("#message")

    correct_button.addEventListener('click', function(){
    correct_button.style.backgroundColor= "#90ee90";
    message.innerHTML="Correct";
})

for( let i=0; i<false_button.length; i++){

    false_button[i].addEventListener('click', function(){
    false_button[i].style.backgroundColor= "#FFCCCB";
    message.innerHTML="Wrong";
    })
}

document.querySelector("#free").addEventListener('click', function(){
    let input=document.querySelector("input")
    let freemessage = document.querySelector("#freemessage")
    if (input.value== "21"){
        input.style.backgroundColor= "#90ee90";
        freemessage.innerHTML="Correct";
    }
    else{
        input.style.backgroundColor= "#FFCCCB";
        freemessage.innerHTML="Wrong";}
})

})