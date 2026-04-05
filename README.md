<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    
</head>
<body>

<h1>War Card Game</h1>

<h2>Overview</h2>
<p>
    This project is a text-based implementation of the classic card game War, written entirely in C.
    The game runs in the terminal and includes:
</p>
<ul>
    <li>A full 52-card deck</li>
    <li>Shuffling using the Fisher–Yates algorithm</li>
    <li>A War mechanic when cards tie</li>
    <li>A special Final Boss Round on round 26</li>
    <li>Player interaction every 5 rounds</li>
    <li>Coloured card output using ANSI escape codes</li>
</ul>

<h2>How the Game Works</h2>

<h3>Basic Rules</h3>
<ul>
    <li>You and the Enemy each draw one card per round.</li>
    <li>The higher card wins and earns 1 point.</li>
    <li>Ranks go from 2 to Ace (14).</li>
</ul>

<h3>War Mechanic</h3>
<p>If both cards have the same rank:</p>
<ol>
    <li>Each player places 3 cards face-down.</li>
    <li>Each draws 1 card face-up.</li>
    <li>The higher card wins the war and earns 2 points.</li>
    <li>If it ties again, the war repeats.</li>
</ol>

<h3>Special Round (Round 26)</h3>
<ul>
    <li>Treated as a Final Boss Battle.</li>
    <li>Only one card is drawn per side.</li>
    <li>Winner earns 3 bonus points.</li>
</ul>

<h3>Player Interaction</h3>
<p>
    Every 5 rounds, the game pauses and waits for the player to press ENTER before continuing.
</p>

<h3>Winning</h3>
<ul>
    <li>Higher score: You win</li>
    <li>Lower score: Enemy wins</li>
    <li>Equal score: Tie</li>
</ul>

<h2>Features Demonstrated</h2>
<ul>
    <li>Use of structs (Card)</li>
    <li>Arrays and deck management</li>
    <li>Functions and modular design</li>
    <li>Loops and conditionals</li>
    <li>Randomisation with srand and rand</li>
    <li>ANSI colour codes for terminal output</li>
</ul>

<h2>How to Compile and Run</h2>

<h3>Using GCC</h3>
<pre><code>gcc WarCardGame.c -o WarCardGame
./WarCardGame
</code></pre>

<h3>Using VS Code</h3>
<ol>
    <li>Open the folder containing the .c file.</li>
    <li>Open the integrated terminal.</li>
    <li>Compile using the command above.</li>
    <li>Run the program.</li>
</ol>

<h2>Gameplay Video</h2>
<p>
    <a href="">Click here to watch the gameplay video</a>
</p>

<h2>File Structure</h2>
<pre><code>/
│── WarCardGame.c
│── README.md
│── REPORT.pdf
│── video.mp4
</code></pre>

<h2>Future Improvements</h2>
<ul>
    <li>Add graphics using raylib</li>
    <li>Animated card movement</li>
    <li>Sound effects</li>
    <li>A menu system</li>
    <li>Add symbols for the spaces, hearts etc</li>
</ul>

</body>
</html>
