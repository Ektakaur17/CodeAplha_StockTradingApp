let board = ["", "", "", "", "", "", "", "", ""];
let currentPlayer = "X";
let gameActive = false;
let mode = null;
let difficulty = "medium";
let scores = { X: 0, O: 0, Draws: 0 };

const statusText = document.getElementById("status");
const scoreX = document.getElementById("scoreX");
const scoreO = document.getElementById("scoreO");
const draws = document.getElementById("draws");
const difficultySelect = document.getElementById("difficulty");

const winCombos = [
  [0,1,2],[3,4,5],[6,7,8],
  [0,3,6],[1,4,7],[2,5,8],
  [0,4,8],[2,4,6]
];

function setMode(selectedMode) {
  mode = selectedMode;
  resetGame();
  gameActive = true;
  statusText.textContent = `Player ${currentPlayer}'s turn`;
  createBoard();
}

function createBoard(){
  const boardContainer = document.getElementById('board');
  boardContainer.innerHTML = '';

  for (let i = 0; i < 9; i++) {
    const cell = document.createElement('div');
    cell.classList.add('cell');
    cell.dataset.index = i;
    cell.addEventListener('click', handleClick);
    boardContainer.appendChild(cell);
  }
}

function changeDifficulty() {
  difficulty = difficultySelect.value;
  console.log("Difficulty set to: " + difficulty);
}

function handleClick(e) {
  const index = e.target.dataset.index;
  if (!gameActive || board[index] !== "") return;

  makeMove(index, currentPlayer);
  if (checkWin(currentPlayer)) {
    endGame(`${currentPlayer} wins`);
    scores[currentPlayer]++;
    updateScores();
  } else if (board.every(cell => cell !== "")) {
    endGame("It's a draw!");
    scores.Draws++;
    updateScores();
  } else {
    currentPlayer = currentPlayer === "X" ? "O" : "X";
    statusText.textContent = `Player ${currentPlayer}'s turn`;

    if (mode === "ai" && currentPlayer === "O") {
      setTimeout(() => {
        const aiMove = getAIMove();
        makeMove(aiMove, "O");
        if (checkWin("O")) {
          endGame("O wins");
          scores.O++;
          updateScores();
        } else if (board.every(cell => cell !== "")) {
          endGame("It's a draw!");
          scores.Draws++;
          updateScores();
        } else {
          currentPlayer = "X";
          statusText.textContent = `Player ${currentPlayer}'s turn`;
        }
      }, 500);
    }
  }
}

function makeMove(index, player) {
  board[index] = player;
  const allCells = document.querySelectorAll(".cell");
  allCells[index].textContent = player;
}

function checkWin(player) {
  return winCombos.some(combo => combo.every(i => board[i] === player));
}

function endGame(msg) {
  gameActive = false;
  statusText.textContent = msg;
}

function resetGame() {
  board = ["", "", "", "", "", "", "", "", ""];
  const allCells = document.querySelectorAll(".cell");
  allCells.forEach(cell => cell.textContent = "");
  currentPlayer = "X";
  if (mode) {
    gameActive = true;
    statusText.textContent = `Player ${currentPlayer}'s turn`;
  } else {
    statusText.textContent = "Choose a mode to start";
  }
}

function updateScores() {
  scoreX.textContent = scores.X;
  scoreO.textContent = scores.O;
  draws.textContent = scores.Draws;
}

function getAIMove() {
  const available = board.map((val, i) => val === "" ? i : null).filter(i => i !== null);

  if (difficulty === "easy") {
    return available[Math.floor(Math.random() * available.length)];
  }

  if (difficulty === "medium") {
    if (Math.random() < 0.5) {
      return minimax(board, "O").index;
    } else {
      return available[Math.floor(Math.random() * available.length)];
    }
  }

  return minimax(board, "O").index;
}

function minimax(newBoard, player) {
  const availSpots = newBoard.map((val, i) => val === "" ? i : null).filter(i => i !== null);

  if (checkWinner(newBoard, "X")) return { score: -10 };
  if (checkWinner(newBoard, "O")) return { score: 10 };
  if (availSpots.length === 0) return { score: 0 };

  const moves = [];

  for (let i = 0; i < availSpots.length; i++) {
    const move = {};
    move.index = availSpots[i];
    newBoard[availSpots[i]] = player;

    if (player === "O") {
      move.score = minimax(newBoard, "X").score;
    } else {
      move.score = minimax(newBoard, "O").score;
    }

    newBoard[availSpots[i]] = "";
    moves.push(move);
  }

  let bestMove;
  if (player === "O") {
    let bestScore = -Infinity;
    for (let i = 0; i < moves.length; i++) {
      if (moves[i].score > bestScore) {
        bestScore = moves[i].score;
        bestMove = i;
      }
    }
  } else {
    let bestScore = Infinity;
    for (let i = 0; i < moves.length; i++) {
      if (moves[i].score < bestScore) {
        bestScore = moves[i].score;
        bestMove = i;
      }
    }
  }

  return moves[bestMove];
}

function checkWinner(b, player) {
  return winCombos.some(combo => combo.every(i => b[i] === player));
}
