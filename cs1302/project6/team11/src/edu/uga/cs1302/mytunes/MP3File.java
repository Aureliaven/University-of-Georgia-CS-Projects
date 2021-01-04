package edu.uga.cs1302.mytunes;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.Map;

import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.AudioFileFormat;

import java.util.Scanner;

/**
 * A class representing a single MP3File and its information.
 * Contains the option to play a .mp3 file if needed.
 */
public class MP3File
{
    // INSTANCE VARIABLES
    private String path;
    private String author;
    private String album;
    private String date;
    private String title;
    private int year;

    /**
     * Default constructor for MP3File.
     * Creates an "empty" object instance.
     */
    public MP3File()
    {
	path = "Unknown";
	author = "No author";
	album = "Unknown";
	date = "0";
	title = "No name";
	year = 0;
    }

    /**
     * Constructor for MP3File with a given path.
     * Retrieves the ID3 tags of given file in the path and initializes the instance variabes with them.
     * @param path the path at which a .mp3 file lies
     */
    public MP3File(String path)
    {
	// retrieving ID3 tags
	try
	    {
		FileInputStream fis = new FileInputStream(path);
		BufferedInputStream bis = new BufferedInputStream(fis);
		AudioFileFormat mpegFormat = AudioSystem.getAudioFileFormat(bis);
		Map properties = mpegFormat.properties();
		
		// initializing instance variables to ID3 tags retrieved
		this.path = path;
		if (properties.get("author") == null)
		    {
			author = "";
		    }
		else
		    {
			author = (String) properties.get("author");
		    }
		if (properties.get("album") == null)
		    {
			album = "";
		    }
		else
		    {
			album = (String) properties.get("album");
		    }
		if (properties.get("date") == null)
		    {
			year = 1900;
		    }
		else
		    {
			date = (String) properties.get("date");
		    }
		if (properties.get("title") == null)
		    {
			title = "";
		    }
		else
		    {
			title = (String) properties.get("title");
		    }
	    }
	catch(ArrayIndexOutOfBoundsException oobe)
	    {
		System.err.println("Usage: java MP3Collection");
	    }
	catch(Exception e)
	    {
		System.out.println(e);
	    }
    }

    // GETTERS AND SETTERS

    /**
     * Returns the path of a MP3File.
     * @return path the path of a MP3File
     */
    public String getPath()
    {
	return path;
    }

    /**
     * Sets the current path of a MP3File to a given path.
     * @param path a path in which to set the current path to
     */
    public void setPath(String path)
    {
	this.path = path;
    }

    /**
     * Returns the author of a MP3File.
     * @return author the author of the MP3File
     */
    public String getAuthor()
    {
	return author;
    }

    /**
     * Sets the current author of a MP3File to a given author.
     * @param author an author in which to set the current author to
     */
    public void setAuthor(String author)
    {
	this.author = author;
    }

    /**
     * Returns the album of a MP3File.
     * @return album the album of the MP3File
     */
    public String getAlbum()
    {
	return album;
    }

    /**
     * Sets the current album of a MP3File to a given album.
     * @param album an album in which to set the current album to
     */
    public void setAlbum(String album)
    {
	this.album = album;
    }

    /**
     * Returns the date of a MP3File.
     * @return date the date of the MP3File
     */
    public String getDate()
    {
	return date;
    }

    /**
     * Sets the current date of a MP3File to a given date.
     * @param date a date in which to set the current date to
     */
    public void setDate(String date)
    {
	this.date = date;
    }

    /**
     * Returns the title of a MP3File.
     * @return title the title of the MP3File
     */
    public String getTitle()
    {
	return title;
    }

    /**
     * Sets the current title of a MP3File to a given title.
     * @param title a title in which to set the current title to
     */
    public void setTitle(String title)
    {
	this.title = title;
    }

    /**
     * Returns the year of a MP3File.
     * @return year the year of the MP3File
     */
    public int getYear()
    {
	return year;
    }

    /**
     * Sets the current year of a MP3File to a given year.
     * @param year a year in which to set the current year to
     */
    public void setYear(int year)
    {
	this.year = year;
    }

    /**
     * Returns the string representation of a MP3File.
     * @return info the string representation of the information of a MP3File
     */
    public String toString()
    {
	String info = "";
	info += "Author: " + author + "\nAlbum: " + album  + "\nTitle: " + title + "\nDate: " + date;  // concatenating instance variables to a string
	return info;
    }

    /**
     * Compares for equality of two MP3File objects.
     * @param file the MP3File object to be compared
     * @return true if objects are equal
     * @return false if objects are not equal
     */
    public boolean equals(MP3File file)
    {
	if (toString().equals(file.toString())) // comparing string representations of each file
	    {
		return true;
	    }
	else
	    {
		return false;
	    }
    }

    /**
     * Plays an MP3File for listening.
     */
    public void play()
    {
	Scanner keyboard = null;
	MP3Player player = new MP3Player();

	if (path.length() <= 0) // if file path name is empty
	    {
		System.err.println("Usage: MP3Collection file.mp3");
		System.exit(1);
	    }
	String fileName = path;
	boolean stop = false;
	String selection = null;

	keyboard = new Scanner(System.in);

	// plays an MP3 file
	while (!stop)
	    {
		player.play(fileName);
		System.out.println("MP3File: Enter 'q' to quit the loop");
		selection = keyboard.next();
		if (selection.equals("q"))
		    {
			stop = true;
		    }
	    }
    }

}
