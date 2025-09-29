# Library Management System 

## Overview
This project implements a **Library Management System** using **C++ and Object-Oriented Programming (OOP)** principles.  
It allows efficient management of books, users, and librarians, supporting operations such as **book issue, return, search**, and request handling.

## Features
- Add, search, issue, and return books  
- Track borrowed books for each user  
- Manage pending book requests using a queue  
- Fast book lookup using **unordered_map (HashMap)**  
- Maintains borrow history using **list**  

## Classes
- **Book** – Represents a book with attributes like ID, title, author, and issue status  
- **User** – Represents a user with ID, name, and borrowed books history  
- **Library** – Core class managing books, users, issuing, returns, and requests  

## Tech Stack
- **Language**: C++  
- **Concepts**: Object-Oriented Programming (OOP), HashMap, Queue, List, Data Structures  
- **Libraries**: STL (`unordered_map`, `list`, `queue`)  

## How It Works
1. Add books and users to the library.  
2. Users can search for books by title.  
3. Books can be issued to users if available; otherwise, they are added to a request queue.  
4. Returned books are updated and allocated to pending requests.

## Future Enhancements
- Add librarian login and roles  
- Store data persistently using files or databases  
- Implement GUI for easier interaction  
