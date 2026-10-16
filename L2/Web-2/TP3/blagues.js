addEventListener("load", function() {
    document.getElementById("form-submit").addEventListener("click", request_blagues);
    form_text = document.getElementById("form-text");

    document.getElementById("pages-number-prev").addEventListener("click", prev);
    document.getElementById("pages-number-next").addEventListener("click", next);
});

let form_text;
let result = null;
let xhr = new XMLHttpRequest();

xhr.responseType = "json";
xhr.onreadystatechange = function() {
    if (xhr.readyState === XMLHttpRequest.DONE) {
        if (xhr.status === 200) {
            result = xhr.response
            console.log(result);
            display_blagues(result);
        } else {
            console.log("Status: " + xhr.status);
            display_blagues(null);
        }
    }
}

function send_request(params)
{
    let url = "https://icanhazdadjoke.com/search";
    let request = url + "?" + params;

    xhr.open("GET", request);
    xhr.setRequestHeader("Accept", "application/json");
    xhr.send();
}

function request_blagues()
{
    let params = "term=" + encodeURIComponent(form_text.value) + "&limit=5&page=1";
    send_request(params)
}

function display_blagues(response)
{
    document.getElementById("tags").style.display = "none";
    document.getElementById("pages").style.display = "none";
    document.getElementById("blagues").innerHTML = "";

    document.getElementById("tags").style.display = "flex";
    document.getElementById("tags-list").innerText = "\"" + form_text.value + "\"";

    if (response === null) {
        blagues.innerHTML = "<div class=\"blague-card\"><p class=\"blague-card-text\">Erreur lors de la récupération des blagues.</p></div>";
        return;
    }

    if (response.results.length === 0) {
        blagues.innerHTML = "<div class=\"blague-card\"><p class=\"blague-card-text\">Aucune blague trouvée.</p></div>";
        return;
    }

    for (let i = 0; i < response.results.length; i++) {
        let blague = response.results[i];
        blagues.innerHTML += "<div class=\"blague-card\"><p class=\"blague-card-text\">" + blague.joke + "</p></div>";
    }

    if (response.total_pages > 1) {
        document.getElementById("pages").style.display = "flex";
        document.getElementById("pages-number").innerText = response.current_page + " / " + response.total_pages;
    }
}

function prev()
{
    let params = "term=" + encodeURIComponent(form_text.value) + "&limit=5&page=" + result.previous_page;
    send_request(params)
}

function next()
{
    let params = "term=" + encodeURIComponent(form_text.value) + "&limit=5&page=" + result.next_page;
    send_request(params)
}