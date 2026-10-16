addEventListener("load", function() {
    document.getElementById("form-submit").addEventListener("click", request_blagues);
    form_text = document.getElementById("form-text");

    document.getElementById("pages-number-prev").addEventListener("click", prev);
    document.getElementById("pages-number-next").addEventListener("click", next);
});

let form_text;
let RequestResponse = null;

function send_request(page = 1)
{
    let url = "https://icanhazdadjoke.com/search";

    let options = {
        method: "GET",
        headers: {
            "Accept": "application/json",
            "Content-Type": "application/json"
        }
    }

    let search = encodeURIComponent(form_text.value);
    let query = "?term=" + search + "&limit=5&page=" + page;
    url += query;

    fetch(url, options).then(response => {
        if (response.ok) {
            response.json().then(data => {
                RequestResponse = data;
                display_blagues();
            }
            ).catch(error => {
                console.log(error);
                display_blagues(null);
            });
        } else {
            console.log("Status: " + response.status);
            RequestResponse = null;
            display_blagues();
        }
    }).catch(error => {
        console.log(error);
        display_blagues(null);

    });
}

function request_blagues()
{
    if (form_text.value === "") {
        return;
    }

    send_request()
}

function display_blagues()
{
    document.getElementById("tags").style.display = "none";
    document.getElementById("pages").style.display = "none";
    document.getElementById("blagues").innerHTML = "";

    document.getElementById("tags").style.display = "flex";
    document.getElementById("tags-list").innerText = "\"" + form_text.value + "\"";

    if (RequestResponse === null) {
        blagues.innerHTML = "<div class=\"blague-card\"><p class=\"blague-card-text\">Erreur lors de la récupération des blagues.</p></div>";
        return;
    }

    if (RequestResponse.results.length === 0) {
        blagues.innerHTML = "<div class=\"blague-card\"><p class=\"blague-card-text\">Aucune blague trouvée.</p></div>";
        return;
    }

    for (let i = 0; i < RequestResponse.results.length; i++) {
        let blague = RequestResponse.results[i];
        blagues.innerHTML += "<div class=\"blague-card\"><p class=\"blague-card-text\">" + blague.joke + "</p></div>";
    }

    if (RequestResponse.total_pages > 1) {
        document.getElementById("pages").style.display = "flex";
        document.getElementById("pages-number").innerText = RequestResponse.current_page + " / " + RequestResponse.total_pages;
    }
}

function prev()
{
    send_request(RequestResponse.previous_page)
}

function next()
{
    send_request(RequestResponse.next_page)
}