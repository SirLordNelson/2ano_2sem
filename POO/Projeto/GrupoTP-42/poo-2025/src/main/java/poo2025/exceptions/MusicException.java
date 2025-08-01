/*
 * Copyright (c) 2025. João Delgado, Nelson Mendes, Simão Mendes
 *
 * License: MIT
 *
 * Permission is granted to use, copy, modify, and distribute this work,
 * provided that the copyright notice and this license are included in all copies.
 */

package poo2025.exceptions;

/**
 * Represents an exception specific to errors related to music operations or processing.
 * This exception serves as a general-purpose mechanism for handling music-related
 * error conditions within the application.
 */
public class MusicException extends Exception {
    /**
     * Constructs a new MusicException with the specified detail message.
     *
     * @param message the detail message providing more information about the exception
     */
    public MusicException(String message) {
        super(message);
    }
}