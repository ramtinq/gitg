/*
 * This file is part of gitg
 *
 * Copyright (C) 2014 - Jesse van den Kieboom
 *
 * gitg is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * gitg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with gitg. If not, see <http://www.gnu.org/licenses/>.
 */

namespace GitgExt
{

public class UserQueryResponse : Object
{
	public string text;
	public Gtk.ResponseType response_type;

	public UserQueryResponse(string text, Gtk.ResponseType response_type)
	{
		this.text = text;
		this.response_type = response_type;
	}
}

public class UserQuery : Object
{
	public string title { get; set; }
	public string message { get; set; }
	public Gtk.MessageType message_type { get; set; }
	public Gtk.ResponseType default_response { get; set; default = Gtk.ResponseType.CLOSE; }
	public UserQueryResponse[] responses { get; set; }

	public signal void quit();
	public signal bool response(Gtk.ResponseType response_type);
}

}

// ex:set ts=4 noet:

