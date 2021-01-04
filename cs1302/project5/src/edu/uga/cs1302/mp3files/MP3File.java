package edu.uga.cs1302.mp3files;
import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.util.Map;

import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.AudioFileFormat;

/** Represents an MP3 file on your computer system
 */
public class MP3File {

    private String path;
    private String author;
    private String album;
    private String date;
    private String title;

    /** Default constructor, sets all attributes to empty Strings
     */
    public MP3File() {
	path = "";
	author = "";
	album = "";
	date = "";
	title = "";
    } // default constructor

    /** Constructor which accepts a path to an MP3 file
     */
    public MP3File (String pathname) {
	try {
	    this.path = pathname;
	    FileInputStream stream = new FileInputStream(pathname);
	    BufferedInputStream buffer = new BufferedInputStream(stream);
	    AudioFileFormat mpegFormat = AudioSystem.getAudioFileFormat(buffer);
	    Map properties = mpegFormat.properties();

	    author = (String) properties.get("author");
	    album = (String) properties.get("album");
	    date = (String) properties.get("date");
	    title = (String) properties.get("title");
	} // try
	catch (ArrayIndexOutOfBoundsException e) {
	    System.err.println("Usage: java PrintMP3Properties file.mp3");
	} // catch
	catch (Exception e) {
	    System.out.println(e);
	} // catch
    } // constructor with path

    /** @return the path of the MP3 file
     */
    public String getPath() {
	return this.path;
    } // getPath

    /** @param the new path of the MP3 file
     */
    public void setPath(String pathname) {
	this.path = pathname;
    } // setPath

    /** @return the author of the MP3 file
     */
    public String getAuthor() {
	return author;
    } // getAuthor

    /** @param the new author of the MP3 file
     */
    public void setAuthor(String author) {
	this.author = author;
    } // setAuthor

    /** @return the album of the MP3 file
     */
    public String getAlbum() {
	return this.album;
    } // getAlbum

    /** @param the new album of the MP3 file
     */
    public void setAlbum(String album) {
	this.album = album;
    } // setAlbum

    /** @return the date of the MP3 file
     */
    public String getDate() {
	return this.date;
    } // getDate

    /** @param the new date of the MP3 file
     */
    public void setDate(String date) {
	this.date = date;
    } // setDate

    /** @return the title of the MP3 file
     */
    public String getTitle() {
	return this.title;
    } // getTitle

    /** @param the new title of the MP3 file
     */
    public void setTitle(String title) {
	this.title = title;
    } // setTitle

    /** @return a String representation of the MP3 file's attributes
     */
    public String toString() {
	return "Path: " + this.path + "\n Title: " + this.title + "\n Author: "
	    + this.author + "\n Album: " + this.album + "\n Date: " + this.date;
    } // toString

    /** Compares the attributes of the given object to the calling object
     * @return true if the objects are equal, false otherwise
     */
    public boolean equals(Object o) {
	if (o instanceof MP3File) {
	    MP3File file = (MP3File) o;
	    if (file.path.equals(this.path) && file.title.equals(this.title) &&
		file.author.equals(this.author) && file.album.equals(this.album) &&
		file.date.equals(this.date)) {
		return true;
	    } // if
	} // if
	return false;
    } // equals

    /** Plays the MP3 file
     */
    public void play() {
	MP3Player player = new MP3Player();
	try {
	    player.play(this.getPath());
	    player.waitForPlaybackFinish();
	} // try
	catch (Exception e) {
	    System.err.println("Invalid path");
	} // catch
    } // play
    
} // class
