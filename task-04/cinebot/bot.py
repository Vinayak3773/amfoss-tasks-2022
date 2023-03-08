import csv

import telebot

from OMDB import get_movie_info

bot = telebot.TeleBot("6061830638:AAHfVFfeCJ3QI5-T3P97P2jYnzRam_q98JE") 

import csv
import json

import requests

@bot.message_handler(commands=['start', 'hello'])
def greet(message):
    global botRunning
    botRunning = True
    bot.reply_to(
        message, 'Hello there! I am a bot that will show movie information for you and export it in a CSV file.\n\n')
    
@bot.message_handler(commands=['stop', 'bye'])
def goodbye(message):
    global botRunning
    botRunning = False
    bot.reply_to(message, 'Bye!\nHave a good time')
    


@bot.message_handler(func=lambda message: botRunning, commands=['help'])
def helpProvider(message):
    bot.reply_to(message, '1.0 You can use \"/movie MOVIE_NAME\" command to get the details of a particular movie. For eg: \"/movie The Shawshank Redemption\"\n\n2.0. You can use \"/export\" command to export all the movie data in CSV format.\n\n3.0. You can use \"/stop\" or the command \"/bye\" to stop the bot.')


@bot.message_handler(func=lambda message: botRunning, commands=['movie'])
def getMovie(message):

    print('hello tooo')
    bot.reply_to(message, 'Getting movie info... ')

    movie_name = message.text
    print('-0-0-')
    print(movie_name)

    movie = movie_name.split(' ', 1)[1]

    movie_info = get_movie_info(movie)

    
    if movie_info:
        rating_string = f"IMDb Rating: {movie_info['imdb_rating']}\n"

        message_text = (f"poster\n{movie_info['Poster']}\n\n" +
            f"{movie_info['title']} ({movie_info['year']}):\n\n" + 
            

            f"Starring:\n{movie_info['actors']}\n\n" +
            f"Ratings:\n{rating_string}"
            ) 

        bot.send_message(message.chat.id,message_text)

        movie=[[movie_info['title'] ,movie_info['year'],movie_info['imdb_rating']]]
        print(movie)



        with open("movies.csv", 'a') as csvfile: 

               csvwriter = csv.writer(csvfile) 
          
               csvwriter.writerows(movie)

        csvfile.close()

        
    else:{
         bot.reply_to(message, 'Movie Not Found...!')

    }

  
@bot.message_handler(func=lambda message: botRunning, commands=['export'])
def getList(message):
    bot.reply_to(message, 'Generating file...Please wait')
    with open("movies.csv", 'r') as csvfile: 

        bot.send_document(message.chat.id,csvfile)
        csvfile.close()

@bot.message_handler(func=lambda message: botRunning)
def default(message):
    bot.reply_to(message, 'I did not understand '+'\N{confused face}')
    
bot.infinity_polling()
