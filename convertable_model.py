import torch
from torch import nn


class G2P(nn.Module):
    def __init__(self, encoder, decoder, hidden_size, eos_token=1, max_len=100):
        super(G2P, self).__init__()
        # model
        self.encoder_model = encoder
        self.decoder_model = decoder
        self.device = torch.device('cpu')
        self.hidden_size = hidden_size
        self.max_len = max_len
        self.eos_token = eos_token

    def forward(self, x):
        with torch.no_grad():
            x = x.transpose(0, 1).contiguous()
            enc = self.encoder_model(x)

        phonemes_index = torch.ones(self.max_len).long()
        x = torch.zeros(1, 1).long().to(self.device)
        hidden = torch.ones(1, 1, self.hidden_size).to(self.device)
        t = 0
        while True:
            with torch.no_grad():
                out, hidden, _ = self.decoder_model(x, enc, hidden)
            max_index = out[0, 0].argmax()
            x = max_index.unsqueeze(0).unsqueeze(0)
            phonemes_index[t] = max_index.detach()
            t += 1
            if max_index.item() == self.eos_token or t > self.max_len:
                break

        return phonemes_index
