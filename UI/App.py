import tkinter as tk

LIGHT_BLUE = "#ADD8E6"
BUTTON_COLOR = "#B0E0E6"  # Slightly darker blue for buttons
HOVER_COLOR = "#87CEEB"   # Color when hovering
TEXT_COLOR = "#000000"    # Black text for contrast
FONT = ("Arial", 14, "bold")  # Font for all buttons


class StyledButton(tk.Button):
    """Custom button with hover effect."""
    def __init__(self, master, **kwargs):
        super().__init__(master, **kwargs)
        self.default_bg = kwargs.get('bg', BUTTON_COLOR)
        self.hover_bg = kwargs.get('activebackground', HOVER_COLOR)
        self.configure(bg=self.default_bg, fg=TEXT_COLOR, font=FONT, bd=0, relief="raised")
        self.bind("<Enter>", self.on_enter)
        self.bind("<Leave>", self.on_leave)

    def on_enter(self, e):
        self['bg'] = self.hover_bg

    def on_leave(self, e):
        self['bg'] = self.default_bg


class WelcomeWindow:
    def __init__(self, root):
        self.root = root
        self.root.title("Welcome Window")
        self.root.geometry("800x500")
        self.root.configure(bg=LIGHT_BLUE)

        label = tk.Label(self.root, text="Welcome to Julian's Spam Email Detector!",
                         font=("Arial", 20, "bold"), bg=LIGHT_BLUE)
        label.pack(pady=40)

        btn_next = StyledButton(self.root, text="Go to Main Menu", command=self.open_main_window)
        btn_next.pack(pady=20)

    def open_main_window(self):
        for widget in self.root.winfo_children():
            widget.destroy()
        MainWindow(self.root)


class MainWindow:
    def __init__(self, root):
        self.root = root
        self.root.title("Main Window")
        self.root.configure(bg=LIGHT_BLUE)

        label = tk.Label(self.root, text="Choose a category", font=("Arial", 18, "bold"), bg=LIGHT_BLUE)
        label.pack(pady=30)

        btn_spam = StyledButton(self.root, text="View Spam Emails", command=self.open_spam_window)
        btn_spam.pack(pady=10)

        btn_ham = StyledButton(self.root, text="View Ham Emails", command=self.open_ham_window)
        btn_ham.pack(pady=10)

        btn_exit = StyledButton(self.root, text="Exit Application", command=self.root.destroy)
        btn_exit.pack(pady=20)

    def open_spam_window(self):
        SpamWindow(self.root)

    def open_ham_window(self):
        HamWindow(self.root)


class SpamWindow:
    def __init__(self, master):
        self.window = tk.Toplevel(master)
        self.window.title("Spam Window")
        self.window.geometry("800x500")
        self.window.configure(bg=LIGHT_BLUE)

        label = tk.Label(self.window, text="Spam Emails are Here", font=("Arial", 16, "bold"), bg=LIGHT_BLUE)
        label.pack(pady=40)

        btn_close = StyledButton(self.window, text="Close Window", command=self.window.destroy)
        btn_close.pack(pady=20)


class HamWindow:
    def __init__(self, master):
        self.window = tk.Toplevel(master)
        self.window.title("Ham Window")
        self.window.geometry("800x500")
        self.window.configure(bg=LIGHT_BLUE)

        label = tk.Label(self.window, text="Your Ham Emails are Here", font=("Arial", 16, "bold"), bg=LIGHT_BLUE)
        label.pack(pady=40)

        btn_close = StyledButton(self.window, text="Close Window", command=self.window.destroy)
        btn_close.pack(pady=20)


def main():
    root = tk.Tk()
    app = WelcomeWindow(root)
    root.mainloop()


if __name__ == "__main__":
    main()
