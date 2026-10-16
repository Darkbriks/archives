let countries = [];

async function getCountries(countrySearch){
    countries = [];
    try{
        if(countrySearch != ""){
            const response = await fetch('https://restcountries.com/v3.1/name/' + countrySearch);
            const json = await response.json();
            for (let country of json) {
                console.log(country);
                let countryObj = {name: country.name.common, capital: country.capital, flagUrl: country.flags.png};
                countries.push(countryObj);
            };
        } else {
            const response = await fetch('https://restcountries.com/v3.1/all');
            const json = await response.json();
            for (let country of json) {
                console.log(country);
                let countryObj = {name: country.name.common, capital: country.capital, flagUrl: country.flags.png};
                countries.push(countryObj);
            };
        }
    } catch (e){
        console.error(e);
    }
}

function showCountries(){
    document.getElementById("countries").innerHTML = "";
    if (countries.length > 0) {
        for (let country of countries) {
            let country_card = document.createElement("div");
            country_card.classList.add("country-card");

            let country_card_content = document.createElement("div");
            country_card_content.classList.add("country-card-content");
            country_card.appendChild(country_card_content);

            let flag = document.createElement("div");
            flag.classList.add("flag");
            country_card_content.appendChild(flag);

            let flagImg = document.createElement("img");
            flagImg.setAttribute("src", country.flagUrl);
            flag.appendChild(flagImg);

            let infos = document.createElement("div");
            infos.classList.add("infos");
            country_card_content.appendChild(infos);

            let country_name = document.createElement("div");
            country_name.classList.add("country-name");
            country_name.innerText = country.name;
            infos.appendChild(country_name);

            let country_capital = document.createElement("div");
            country_capital.classList.add("country-capital");
            country_capital.innerText = country.capital;
            infos.appendChild(country_capital);
            
            document.getElementById("countries").appendChild(country_card);
        }
    } else {
        document.getElementById("countries").innerText = "Aucun résultat trouvé";
    }
}

document.getElementById("search").onclick = async function(){
    await getCountries(document.getElementById("countrySearch").value);
    showCountries();
}

// Afficher tous les pays au chargement de la page
document.addEventListener("DOMContentLoaded", async function(){
    await getCountries("");
    showCountries();
});