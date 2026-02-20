// const express = require('express');
// const path = require('path');
// const app = express();
// const PORT = 3000;

// // Middleware to parse form data from the HTML body
// app.use(express.urlencoded({ extended: true }));

// // 1. Route to serve the login page
// app.get('/', (req, res) => {
//     res.sendFile(path.join(__dirname, 'index.html'));
// });

// // 2. Route to handle the login submission
// app.post('/login', (req, res) => {
//     // Extract username and password from the form
//     const { username, password } = req.body;

//     // Simple check (In a real app, you would check a database)
//     if (username === 'admin' && password === '12345') {
//         res.send(`<h1>Welcome, ${username}!</h1><p>Login Successful.</p>`);
//     } else {
//         res.send('<h1>Login Failed</h1><a href="/">Try again</a>');
//     }
// });

// // Start the server
// app.listen(PORT, () => {
//     console.log(`Server running at http://localhost:${PORT}`);
// });

<html lang="en">
<body>

</body>
