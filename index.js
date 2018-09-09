const express = require('express')
const path = require('path')
require('dotenv').config()

const app = express()
const { PORT } = process.env

app.set('views', path.join(__dirname, 'views'))
app.set('view engine', 'ejs')

app.get('/', (req, res) => res.render('index'))

app.listen(PORT, () => console.log(`⚡️⚡️ Server started on port ${PORT}`))
