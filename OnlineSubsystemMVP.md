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
