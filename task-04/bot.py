import os
import telebot
import requests
import json
import csv

# TODO: 1.1 Get your environment variables 
yourkey ="60893b7e"
bot_id = "5836453032:AAH09MrKlGxNnU8Ki6OELG9B8gp3PuX4GsE"

bot = telebot.TeleBot(bot_id)

@bot.message_handler(commands=['start', 'hello'])
def greet(message):
    global botRunning
    botRunning = True
    bot.reply_to(
        message, 'Hello there! I am a bot that will show mov information for you and export it in a CSV file.\n\n')
    
@bot.message_handler(commands=['stop', 'bye'])
def goodbye(message):
    global botRunning
    botRunning = False
    bot.reply_to(message, 'Bye!\nHave a good time')
    


@bot.message_handler(func=lambda message: botRunning, commands=['help'])
def helpProvider(message):
    bot.reply_to(message, '1.0 You can use \"/movie MOVIE_NAME\" command to get the details of a particular mov. For eg: \"/movie The Shawshank Redemption\"\n\n2.0. You can use \"/export\" command to export all the mov data in CSV format.\n\n3.0. You can use \"/stop\" or the command \"/bye\" to stop the bot.')


@bot.message_handler(func=lambda message: botRunning, commands=['movie'])
def getMovie(message):
    bot.reply_to(message, 'Getting movie info...')
    mov = message.text
    mov = mov.replace("/movie","")
    response = requests.get( f"http://www.omdbapi.com/?apikey=bcd3f769&t={mov}")
    mov_info=response.json()
    print(json.dumps(mov_info,indent = 4))
    bot.reply_to(message,f"{mov_info['Poster']} \nMovie Name: {mov_info['Title']} \nImdb Rating: {mov_info['imbdRating']} \nYear: {mov_info['Year']} \nReleased: {mov_info['Released']}")
    bot.send_photo(message,{mov_info['Poster']})
    with open('mov_data.csv', 'a') as f:
        writer = csv.writer(f)
        writer.writerow([mov_info['Title'],mov_info['imbdRating'],mov_info['Year'],mov_info['Released']])


  
@bot.message_handler(func=lambda message: botRunning, commands=['export'])
def getList(message):
    bot.reply_to(message, 'Generating file...')
    chat_id = message.chat.id 
    print()
    mov_info=open('mov_data.csv','rb')
    bot.send_document(chat_id,mov_info)
    

@bot.message_handler(func=lambda message: botRunning)
def default(message):
    bot.reply_to(message, 'I did not understand '+'\N{confused face}')
    
bot.infinity_polling()
