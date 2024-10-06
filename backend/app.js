const express = require('express');
const { exec } = require('child_process');

const app = express();
app.use(express.json());

app.post('/api/book', (req, res) => {
  const { name, email, show } = req.body;
  exec(`../c_programs/book_ticket "${name}" "${show}"`, (error, stdout) => {
    if (error) {
      console.error(`Error: ${error.message}`);
      return res.status(500).send('Booking failed');
    }
    const bookingId = stdout.trim();
    res.json({ bookingId });
  });
});

app.listen(3001, () => {
  console.log('Server running on http://localhost:3001');
});
