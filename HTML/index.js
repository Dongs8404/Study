const express = require('express')
const cheerio = require('cheerio')

const server = express()
const port = 80

console.log('express 서버 생성')

server.set('view engine', 'ejs')

// 메인 페이지
server.get('/', function(req, res) {

    console.log('/ 요청 옴!!')

    res.sendFile(__dirname + '/index.html')
})

// welcome 페이지
server.get('/welcome', function(req, res){

    console.log('웰컴 요청들어옴!!')

    const userName = req.query.name ?? '익명'

    console.log(req.query)

    res.render('welcome', { userName })
})

var cache = null;

// 메뉴 페이지
server.get('/menu', function(req, res){


    if   (cache != null)
    {
        console.log('캐시에서 처리함');
        res.render('menu', {menuList});
        return;
    }

    fetch('https://kopo.ac.kr/jinju/content.do?menu=6767')
    .then(r => r.text())
    .then(r => {

        const menuList = parseMealTable(r)

        console.log(menuList)

        res.render('menu', { menuList })
    })
    .catch(err => {

        console.log(err)

        res.send('급식 데이터를 불러오는데 실패했습니다.')
    })
})

// 뉴스 페이지
server.get('/news', (req, res) => {

    res.send('This is news page')
})

// 서버 시작
server.listen(port, () => {

    console.log(`Example app listening on port ${port}`)
})

console.log('서버시작')

// 급식 파싱 함수
function parseMealTable(html) {

    const $ = cheerio.load(html)

    const result = []

    // 모든 tr 검사
    $('tr').each((i, tr) => {

        const tds = $(tr).find('td')

        // td 4개 미만이면 스킵
        if (tds.length < 4) return

        const firstTdHtml = $(tds[0]).html()

        if (!firstTdHtml) return

        // 날짜 추출
        const dateMatch = firstTdHtml.match(/getDay2\('([\d-]+)/)

        const date = dateMatch ? dateMatch[1] : null

        // 날짜 없으면 스킵
        if (!date) return

        // 요일 추출
        const dayMatch = $(tds[0])
            .text()
            .match(/(월요일|화요일|수요일|목요일|금요일|토요일|일요일)/)

        const day = dayMatch ? dayMatch[1] : ''

        // 메뉴 문자열 -> 배열 변환
        const parseMenu = (td) => {

            const text = $(td)
                .text()
                .replace(/\s+/g, ' ')
                .trim()

            if (!text) return []

            return text
                .split(',')
                .map(v => v.trim())
                .filter(Boolean)
        }

        result.push({

            date,
            day,

            breakfast: parseMenu(tds[1]),
            lunch: parseMenu(tds[2]),
            dinner: parseMenu(tds[3]),
        })
    })

    return result
}