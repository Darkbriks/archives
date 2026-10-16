let articleList = document.querySelectorAll('article')
let sidebar = document.getElementById('sidebar')

sidebar.innerHTML = "<ul></ul>"

articleList.forEach(article => {
    let title = article.querySelector('h1').innerHTML
    let li = document.createElement('li')
    let a = document.createElement('a')
    article.setAttribute('id', title)
    a.innerHTML = title
    a.setAttribute('href', '#' + title)
    li.appendChild(a)
    sidebar.querySelector('ul').appendChild(li)
})