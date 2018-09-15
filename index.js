const express = require('express')
const path = require('path')
const bodyParser = require('body-parser')
const mongoose = require('mongoose')
const morgan = require('morgan')
const Entry = require('./models/entry')

require('dotenv').config()

const app = express()
const { MONGODB_URI, PORT } = process.env

mongoose.connect(MONGODB_URI)
app.use(morgan('dev'))

app.set('views', path.join(__dirname, 'views'))
app.set('view engine', 'ejs')
app.use(bodyParser.json())

// Single post endpoint, so just doing it on the root
app.post('/', (req, res) => {
  const entry = new Entry()

  const publishedAt = req.body.published_at
  const createdAt = new Date(publishedAt)
  const duration = req.body.data

  entry.createdAt = Number(createdAt)
  entry.duration = Number(duration)

  entry.save(err => {
    // Always need to send back a 200
    // Particle will shut down the account if there are too many errors
    res.status(200)

    if (err) {
      res.json(err)
    }

    const responseBody = req.body
    responseBody.message = 'success'
    res.json(responseBody)
  })
})

// Catch-all route
app.get('*', (req, res) => {
  Entry.find((err, entries) => {
    if (err) {
      res.send(err)
    }

    res.render('index', { entries })
  })
})

app.listen(PORT, () => console.log(`⚡️⚡️ Server started on port ${PORT}`))
