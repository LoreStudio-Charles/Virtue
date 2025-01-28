# What is the Minimum Viable Product for SearedOnlineSubsystem
This document will catalog the changes we need to make to develop the SearedOnlineSubsystem which will provide us the ability to develop a backend for Virtue and other games in the future.

## What Interfaces do we need to create a session and play Virtue in multiplayer?
The following table lists the interfaces which we must support in order to support a multiplayer experience in Virtue. Note that we might not have to fully implement each of these interfaces, but we certainly will need some features within each of these interfaces.
| Interface | Description of desired functionality |
| :---: | :--- |
| [Achievements](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Plugins/OnlineSubsystem/Interfaces/IOnlineAchievements)<sup>1</sup> | When we are ready to track achievements, we will implement this interface. |
| [Chat](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Plugins/OnlineSubsystem/Interfaces/IOnlineChat/) | When we are ready to implement a chat system, we will need to implement this interface. I think this is for chat when connected to our service, and not necessarily in game but must research further to know for certain.<sup>1</sup> |
| [External UI](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Plugins/OnlineSubsystem/Interfaces/IOnlineExternalUI) | We need a means to allow users to authenticate with our services to link them to their account and characters. |
| [Friends](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Plugins/OnlineSubsystem/Interfaces/IOnlineFriends)<sub>2</sub> | We need a way for players to make friends and join a community. |
| [Game Activity](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Plugins/OnlineSubsystem/Interfaces/IOnlineGameActivity) | I think this is how we join sessions, but I will need a spike to verify that we need this. |
| [Groups](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Plugins/OnlineSubsystem/Interfaces/IOnlineGroups)<sup>2</sup> | I think this is like account level guilds? Will need to research more. |
| [Identity](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Plugins/OnlineSubsystem/Interfaces/IOnlineIdentity) | We need to know who is playing. Have they purchased the game? If we are using a subscription model, are they subscribed? |
| [Lobby](https://src.redpoint.games/redpointgames/online-interfaces)<sup>1</sup> | This interface is third party, but would allow us to create a lobby experience where players can queue up to join a session, talk in the lobby, and await the game start together. |
| [Message](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Plugins/OnlineSubsystem/Interfaces/IOnlineMessage)<sup>1</sup> | I think this is for sending messages to friends outisde the game, but needs to do more research. |
| [Online Party](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Plugins/OnlineSubsystem/Interfaces/IOnlinePartySystem?application_version=5.5) | I think this is for forming groups? Need more research. |
| [Presence](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Plugins/OnlineSubsystem/Interfaces/IOnlinePresence)<sup>1</sup> | Shows who among your friends is online. Don't think we want this, but it's a team decision. |
| [Session](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Plugins/OnlineSubsystem/Interfaces/IOnlineSession) | Finding and joining an online session. Unless we use lobbies, we will require this to do matchmaking. |
| [User](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Plugins/OnlineSubsystem/Interfaces/IOnlineUser) | Stores information about the user. Different from the Identity because this is general info versus authenitcation and registration with our services. |


<sup>1</sup> These may not be a priority for MVP, but we should discuss what we desire here as a team.
<sup>2</sup> It seems likely that we may choose instead to do this in game, but this is a team decision. We may also go the Blizzard route and do both in game and in service level friends.

### This is Only for MVP
There is so much more that we will want to add as we develop our own Online Service. We are basically building Steam, Epic Online, or BattleNet from the ground up. Anything that these services present is possible. (Stores, achievements, online character viewer, databases, etc.)

We just can't swallow the elephant in one bite. For Virtue we will determine the minimum set of items we want to support and build that.


## Guide to implementing interfaces

### Order of implementation
| Priority | Interface |
| :---: | :--- |
| 1 | Identity |

### Achiements
Coming soon...

### Chat
Coming soon...

### External UI
Coming soon...

### Friends
Coming soon...

### Game Activity
Coming soon...

### Groups
Coming soon...

### Identity
The identity allows us to authenticate players and ensure that players are required to have an account with our online service to play the game.

This is a large interface, but we may not require everything available.

The identity service will require coordination with the User Interface for some aspects, such as collecting username and passwords during login. Contracts should be defined as we discover our needs.

For example the login contract *might* be defined as:

***Login Contract***
```js
UserAuthRequest: { 
  username: string,
  password: string
}
UserAuthResult: {
	isSuccessful: bool,
	auth_token: string,
	refresh_token: string
}
```

#### Delegates
##### OnAuthAboutToExpireDelegates
This will be called whenever a user's auth token will expire. This should trigger a request to the identity server with the user's refresh token. If the refresh token is valid, then we return a new auth token.

If the refresh token is expired or invalid we need to prompt the player that they must reauthenticate to continue playing and allow them a limited time to reach safety and reauthenticate.

##### OnLoginChangedDelegates
When a player logs in we should get information about their characters available and store that information somewhere in the client so they can make use of it.
When a player logs out, we should make sure we clean up any data related to that player and close any open connections. This would include leaving any open game sessions gracefully.

##### OnLoginCompleteDelegates
After logging in this will trigger anything related to the UI that will indicate to the player that they are ready to select a character.
After logging out, this will trigger anything related to the UI that will indicate that the player can login.

#### Functions
##### AddOnAuthAboutToExpireDelegate_Handle
This allows us to add a listener to the list of ***OnAuthAboutToExpireDelegates*** that will be called when a player's auth token is about to expire.

##### Login
Note: The documentation lists AccountCredentials as a type. The closest I could find in the docs is this struct [FOnlineAccountCredentials](https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Plugins/OnlineSubsystem/Interfaces/FOnlineAccountCredentials?application_version=5.5).
