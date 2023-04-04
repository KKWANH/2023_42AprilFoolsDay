package main

import (
	"fmt"
	"log"
	"net/smtp"
)

func main() {
	from := "kwanho0096@gmail.com"
	password := "gtzzofbzoheclman"
	to := "dosadol741@naver.com"

	// Subject and body
	subject := "Hello, this is the subject"
	body := "Hello, this is the email body."

	err := sendMail(from, password, to, subject, body)
	if err != nil {
		log.Fatalf("Error sending email: %v", err)
	} else {
		fmt.Println("Email sent successfully!")
	}
}

func sendMail(from, password, to, subject, body string) error {
	smtpServer := "smtp.gmail.com"
	auth := smtp.PlainAuth("", from, password, smtpServer)

	msg := "From: " + from + "\n" +
		"To: " + to + "\n" +
		"Subject: " + subject + "\n\n" +
		body

	err := smtp.SendMail(smtpServer+":587", auth, from, []string{to}, []byte(msg))
	if err != nil {
		return err
	}
	return nil
}
