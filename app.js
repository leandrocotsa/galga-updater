const express = require('express')
const app = express()
const port = 3000

var galga_status = "a galga morreu"

app.use(express.urlencoded({ extended: true }));
app.use(express.json())

app.get('/', (req, res) => {
    res.send(galga_status)
})

// POST method route
app.post('/', (req, res) => {
    console.log("A new galga update was received: ")
    console.log(req.body)
    galga_status = req.body["new_status"]
    res.send(galga_status)
})

app.listen(port, () => {
})