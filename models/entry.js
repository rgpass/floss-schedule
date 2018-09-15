const mongoose = require('mongoose')

const { Schema } = mongoose

const EntrySchema = new Schema({
  createdAt: { type: Number, required: true },
  duration: { type: Number, required: true },
})

module.exports = mongoose.model('Entry', EntrySchema)
