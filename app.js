const express = require('express')
const app = express()
const port = 3000

var galga_status = "A GALGA MORREU"

app.use(express.urlencoded({ extended: true }));
app.use(express.json())

app.get('/', (req, res) => {
    console.log("Someone requested galga's status")
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